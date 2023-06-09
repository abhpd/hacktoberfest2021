use std::fmt;

pub struct Stack<T> {
    stack: Vec<T>
}

impl<T> Stack<T> {
    pub fn new() -> Self {
        Self { stack: Vec::new() }
    }

    pub fn push(&mut self, item: T) {
        self.stack.push(item);
    }

    pub fn pop(&mut self) -> Option<T> {
        self.stack.pop()
    }

    pub fn is_empty(&self) -> bool {
        self.stack.len() == 0
    }

    pub fn peek(&self) -> Option<&T> {
        self.stack.last()
    }
}

impl<T> fmt::Display for Stack<T>
    where T: fmt::Display {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        for i in self.stack.iter().rev() {
            write!(f, "{} ", i)?;
        }
        write!(f, "")
    }
}