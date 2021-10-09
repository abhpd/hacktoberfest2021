/**
 * @author Paul Dikty
 *
 * A slot map is a type of map. One major difference between this type and the
 * stl map is that keys/indices are generated (they cannot be choosen freely)
 * when an element is inserted.
 *
 * This type of map can be used in situations where many elements have to be
 * created in a short time and accessed in a constant time. The elements in a
 * slot map are tightly packed in memory to prevent cache misses which boosts
 * performance when iterating over all elements.
 *
 * Example:
 *      In a game where each element of the slot_map represents an entity.
 *
 * For further information:
 * 		Allan Deutsch: slot_map Container in C++,
 * http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0661r0.pdf
 */

// used by the slot map implementation
#include <limits> // std::numeric_limits
#include <vector>

// used for the example
#include <cstddef>  // size_t
#include <iostream> // std::cout, std::endl
#include <string>

/**
 * @brief A basic slot map.
 *
 * Provides a packed map lke storage of elements.
 * Elements are accessed/identified using numerical ids.
 *
 * @warning This slot map type doesn't check if an id is valid
 *
 * @tparam TElement The type of the stored data
 * @tparam TId The type of the id has to be a numeric type
 */
template <class TElement,
          class TElementID = typename std::vector<TElement>::size_type>
class basic_slot_map
{
    static_assert(std::is_integral<TElementID>::value,
                  "TId has to be of a numeric type, will be used as an index "
                  "into an array");
    static_assert(std::is_unsigned<TElementID>::value,
                  "TId has to be of a unsigned type, will be used as an index "
                  "into an array");

public:
    typedef typename std::vector<TElement>          data_container;
    typedef typename std::vector<TElementID>        erase_container;
    typedef typename std::vector<TElementID>        indices_container;
    typedef typename data_container::iterator       iterator;
    typedef typename data_container::const_iterator const_iterator;
    typedef TElementID                              id_type;
    typedef TElementID                              size_type;
    typedef TElement                                value_type;

    static constexpr TElementID InvalidId =
        std::numeric_limits<TElementID>::max();

    /**
     * @brief Construct a new slot map (empty).
     */
    basic_slot_map()
        : free_head_(EndOfFreeListValue), free_tail_(EndOfFreeListValue)
    {}

    /**
     * @brief Construct a new basic slot map with an initial capacity.
     * @param initial_capacity The initial capacity of the linked list.
     */
    basic_slot_map(size_type initial_capacity)
        : free_head_(EndOfFreeListValue), free_tail_(EndOfFreeListValue)
    {
        indices_.reserve(initial_capacity);
        data_.reserve(initial_capacity);
        erase_.reserve(initial_capacity);
    }

    /**
     * @brief Access the stored data.
     */
    inline data_container& data() { return data_; }
    /**
     * @brief Access the stored data.
     */
    inline const data_container& data() const noexcept { return data_; }

    inline iterator       begin() noexcept { return data_.begin(); }
    inline iterator       end() noexcept { return data_.end(); }
    inline const_iterator cbegin() const noexcept { return data_.cbegin(); }
    inline const_iterator cend() const noexcept { return data_.cend(); }

    /**
     * @brief Generate a container filled with all valid indices.
     */
    inline indices_container valid_indices() const
    {
        indices_container indices;
        indices.reserve(size());
        for (const auto& erase : erase_)
            indices.push_back(indices_[erase]);
        return indices;
    }

    /**
     * @brief Access the element identified by its id.
     *
     * @param id The id of the element to access.
     * @return TElement& Reference to the element identified by its id.
     */
    inline value_type& get(id_type id) { return data_[indices_[id]]; }

    /**
     * @brief Gets the element identified by an id.
     *
     * @param id The id of the element to get.
     * @return TElement& The element identified by id.
     */
    inline value_type& operator[](id_type id) { return get(id); }

    inline size_type size() const noexcept
    {
        return static_cast<size_type>(data_.size());
    }

    /**
     * @brief Check if the id might be valid.
     *
     * @warning Only checks if the id is in bounds of the indices.
     * The id might cause an error even if true was returned.
     *
     * @param id The id to check.
     * @returns true The id is in bounds of the indices -> might be valid
     */
    inline bool valid(id_type id) const noexcept
    {
        return id <= static_cast<id_type>(indices_.size());
    }

    template <class... Args>
    inline id_type emplace(Args&&... args)
    {
        id_type id = _reserve_slot();
        data_.emplace_back(std::forward<Args>(args)...);
        erase_.push_back(id);
        return id;
    }

    /**
     * @brief Inserts a new element into the slot map
     *
     * @param [in] element The element to insert
     * @return id_type The id that the inserted element can be accessed with
     */
    inline id_type insert(value_type&& element)
    {
        id_type id = _reserve_slot();
        data_.push_back(std::move(element));
        erase_.push_back(id);
        return id;
    }

    /**
     * @brief Remove an element form the slot map
     * @param [in] id The id of the element to remove
     */
    inline void remove(id_type id)
    {
        // index of the elment in the data container
        id_type index = indices_[id];

        // mark indice as the end of the free list
        indices_[id] = EndOfFreeListValue;

        // append id to linked list of free indices
        if (_free_list_empty())
        {
            free_head_ = id;
        }
        else
        {
            indices_[free_tail_] = id;
        }
        free_tail_ = id;

        // fill new gap with last element in data container -> continuous
        // placement of elements
        if (index != data_.size() - 1)
        {
            std::swap(data_[index], data_.back());
            std::swap(erase_[index], erase_.back());

            indices_[erase_[index]] = index;
        }
        data_.pop_back();
        erase_.pop_back();
    }

    /**
     * @brief Clears only the stored data.
     *
     * Will invalidate all ids.
     */
    inline void clear()
    {
        // mark all ids as free
        free_head_ = 0;
        free_tail_ = indices_.size();
        for (id_type i = 0; i < free_tail_; i++)
            indices_[i] = i + 1;

        data_.clear();
        erase_.clear();
    }

    /**
     * @brief Works similar to clear but will also reset
     * the slot map as if it was newly created.
     */
    inline void reset()
    {
        indices_.clear();
        data_.clear();
        erase_.clear();

        free_head_ = EndOfFreeListValue;
        free_tail_ = EndOfFreeListValue;
    }

private:
    static constexpr id_type EndOfFreeListValue = InvalidId;

    /**
     * @brief Simple helper function to check if the linked list of free indices
     * is empty.
     */
    inline bool _free_list_empty() const noexcept
    {
        return free_head_ == EndOfFreeListValue;
    }

    /**
     * @brief Reserve a new slot at the end of the data container.
     *
     * @return id_type The id that the inserted element can be accessed with
     */
    inline id_type _reserve_slot()
    {
        id_type id = 0;
        if (_free_list_empty())
        {
            // create new id slot
            // let the index of the new id point to the end of the data
            // container
            id = indices_.size();
            indices_.push_back(data_.size());
        }
        else
        {
            // reuse unused slot
            id = free_head_;

            // update the free list
            free_head_ = indices_[id];
            if (_free_list_empty())
                free_tail_ = free_head_;

            // let the index of the new id point to the end of the data
            // container
            indices_[id] = data_.size();
        }
        return id;
    }

    /**
     * @brief Vector of indices indexing into the data vector.
     *
     * When an indice is free it is used as a index
     * to the next free indice (works like a linked list).
     */
    indices_container indices_;
    /**
     * @brief The stored elements of the slot map.
     */
    data_container data_;
    /**
     * @brief Allows for easy/fast erasing of elements, contains the
     * index of the id that points to an element.
     */
    erase_container erase_;

    /**
     * @brief The head of the free indice linked list.
     *
     * When it has the value @code EndOfFreeListValue @endcode
     * the linked list is considered to be empty.
     */
    id_type free_head_;
    /**
     * @brief The tail of the free indice linked list.
     */
    id_type free_tail_;
};

struct test_element
{
    test_element() : test_element("") {}
    test_element(const char* string) : string(string) {}

    std::string string;
};

//##############################################//
//-----------------Simple usage-----------------//
//##############################################//

int main()
{
    // slot map implementation works with basic types
    basic_slot_map<int> int_map(10);

    basic_slot_map<int>::id_type ids[10];
    for (size_t i = 0; i < 10; i++)
    {
        ids[i] = int_map.insert(10 - i);
    }

    std::cout << "iterate using ids" << std::endl;
    for (auto id : ids)
    {
        std::cout << "id: " << id << ", stored value: " << int_map[id]
                  << std::endl;
    }
    std::cout << std::endl;

    std::cout << "iterate using packed data array:" << std::endl;
    for (const auto& element : int_map)
    {
        std::cout << "stored value: " << element << std::endl;
    }
    std::cout << std::endl;

    // also works with structs/classes
    std::cout << "slot map with more complex types:" << std::endl;
    basic_slot_map<test_element> test_element_map;

    auto element1 = test_element_map.emplace("element1");
    auto element2 = test_element_map.emplace("element2");
    auto element3 = test_element_map.emplace("element3");

    test_element_map.remove(element2);
    // unused ids may be reused
    element2 = test_element_map.emplace("element2");

    std::cout << "element with id " << element3 << ": "
              << test_element_map[element3].string << std::endl;
    std::cout << "element with id " << element2 << ": "
              << test_element_map[element2].string << std::endl;
    std::cout << "element with id " << element1 << ": "
              << test_element_map[element1].string << std::endl;
}