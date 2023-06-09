function Queue () { 
    collection = [];
	
	//print the elements of Queue
    this.print = function() {
        console.log(collection);
    };
	
	//add an element to the queue
    this.enqueue = function(element) {
        collection.push(element);
    };
	
	//remove an element from the queue
    this.dequeue = function() {
        return collection.shift(); 
    };
	
	//return the front element of the queue
    this.front = function() {
        return collection[0];
    };
	
	//return the size of the queue
    this.size = function() {
        return collection.length; 
    };
	
	//check if the queue has no elements
    this.isEmpty = function() {
        return (collection.length === 0); 
    };
}
