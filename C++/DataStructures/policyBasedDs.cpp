#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define T pair<int, int>
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

int getless(ordered_set &os, int R, int index)
{
    return os.order_of_key({R, index});
}

int main(){

    ordered_set os1;   
    // if we want multiset instead of set then we can take idx = 1;
    // and at every insertion we can increase the value of ++idx
    // so insertion would be like this
    //os1.insert({val,++idx});
        
    // when we need getless -> then use the appropriate value of index
    // like if it's multiset then index can be taken as 1e9, so it will return the (values < R && < index)
    
    /************ Example *************/
    os1.insert({0,0});
    os1.insert({1,1});
    os1.insert({2,5});
    cout<<getless(os1, 2, 1e9); // gives 3
    cout<<getless(os1, 2, 5);   // gives 2
    
    return 0;
}
