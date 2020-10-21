class Stack {
    constructor() {
        this.items = [];
        this.top = null;
    }

    getTop() {
        if (this.items.length == 0)
            return null;
        return this.top;
    }

    isEmpty() {
        return this.items.length == 0;
    }

    size() {
        return this.items.length;
    }

    push(element) {
        this.items.push(element);
        this.top = element;
    }

    pop() {
        if (this.items.length != 0) {
            if (this.items.length == 1) {
                this.top = null;
                return this.items.pop();
            } else {
                this.top = this.items[this.items.length - 2];
                return this.items.pop();
            }

        } else
            return null;
    }


}

function isBalanced(exp) {
	var myStack = new Stack();
	//Iterate through the string exp
	for (var i = 0; i < exp.length; i++) {
		//For every closing parenthesis check for its opening parenthesis in stack


		if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {

			if (myStack.isEmpty()) {

				return false
			}
			let output = myStack.pop();
			//If you can't find the opening parentheses for any closing one then returns false.
			if (((exp[i] == "}") && (output != "{")) || ((exp[i] == ")") && (output != "(")) || ((exp[i] == "]") && (output != "["))) {
				return false;
			}

		} else {
			//For each opening parentheses, push it into stack
			myStack.push(exp[i]);
		}

	}
	//after complete traversal of string exp, if there's any opening parentheses left
	//in stack then also return false.
	if (myStack.isEmpty() == false) {
		return false
	}
	//At the end return true if you haven't encountered any of the above false conditions.
	return true
}


var inputString = "{[()]}"
console.log(inputString)
console.log(isBalanced(inputString))

inputString = "{[([({))]}}"
console.log(inputString)
console.log(isBalanced(inputString))