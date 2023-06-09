mod stack;

use stack::Stack;

fn main() {
    let mut stack: Stack<u8> = Stack::new();

    stack.push(0);
    stack.push(1);
    stack.push(2);
    stack.push(3);

    println!("{}", stack);

    println!("{}", stack.pop().unwrap());
    println!("{}", stack.pop().unwrap());

    println!("{}", stack.peek().unwrap());

    println!("{}", stack);
}