var array;
array = ["1","2","3"];
array[0] = ["4","6","7"];
array[0][0] = ["5","8","9"];
array[0][1] = ["we","we2","we3"];
array[0][1][2] = ["soon","soon2","soon3"];
array[1] = ["get"];
array[1][0] ="get2";
array[2] = ["set","set2","set3"];
array[2][0] = "ready";
array[2][1] = ["123","334"];
array[2][2] ="cry";

function getAllNestedElements(arr) {
	var result = [];
    for(var i=0; i<arr.length; i++) {
    	if (Array.isArray(arr[i])) {
        	result = result.concat(getAllNestedElements(arr[i]));
        }
        else {
        	result.push(arr[i]);
       	}
    }
    return result;
}

console.log(getAllNestedElements(array));