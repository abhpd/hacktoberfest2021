fun merge(vararg a: Int, vararg b: Int): Array<Int> {

    var r = Array<Int>(a.size + b.size)
    var i = 0
    var j = 0

    for (i < a.size && j < b.size) {

        if a.get(i) <= b.get(j) {
            r.get(i+j) = a.get(i)
            i++
        } else {
            r.get(i+j) = b.get(j)
            j++
        }

    }

    for i < a.size {
        r.get(i+j) = a.get(i)
        i++
    }
    for j < b.size {
        r.get(i+j) = b.get(j)
        j++
    }

    return r

}

//Mergesort Perform mergesort on a slice of ints
fun Mergesort(vararg items: Int):  Array<Int>  {

    if items.size < 2 {
        return items

    }

    var middle = items.size / 2

    val firstHalf = items.copyOfRange(0, (items.size + 1) / 2)
    val secondHalf = items.copyOfRange((items.size + 1) / 2, items.size)

    var a = Mergesort(firstHalf)
    var b = Mergesort(secondHalf)
    return merge(a, b)

}