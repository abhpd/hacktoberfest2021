// need rustc compiler for compile this code
// after complation, run ./linkd_tree

use std::io::Write;

struct Node {
    data: isize,
    next_node: Option<Box<Node>>
}

impl Node {
    fn new(n: isize) -> Node {
        Node {
            data: n,
            next_node: None
        }
    }
    fn add(&mut self, new_number: isize) {
        if let Some(next_node) = &mut self.next_node {
            next_node.add(new_number);
        } else {
            self.next_node = Some(Box::new(Node::new(new_number)));
        }
    }
    fn remove_last(&mut self) -> bool {
        if let Some(next) = &mut self.next_node {
            if let Some(_) = &next.next_node {
                next.remove_last();
            } else {
                self.next_node = None;
                return true;
            }
        }
        false
    }
    fn show(&self) {
        println!("{}", self.data);
        if let Some(next) = &self.next_node {
            next.show();
        }
    }
}

fn main() {
    let mut node_root: Option<Node> = None;

    loop {
        println!("select the options:");
        println!("1 - show the list");
        println!("2 - add a number");
        println!("3 - remove the last number");
        println!("4 - out of program");

        print!("> ");
        let op = get_input();
        match op {
            1 => {
                match node_root {
                    Some(ref node) => {
                        println!("the list:");
                        node.show();
                    },
                    None => println!("list is empty")
                }
            },
            2 => {
                match node_root {
                    Some(ref mut node) => {
                        print!("number?: ");
                        let number = get_input();
                        node.add(number);
                    },
                    None => {
                        print!("number?: ");
                        let number = get_input();
                        node_root = Some(Node::new(number));
                    }
                }
            },
            3 => {
                match node_root {
                    Some(ref mut node) => {
                        if !node.remove_last() {
                            node_root = None;
                        }
                        println!("the last number removed!");
                    },
                    None => println!("list is empty")
                }
            },
            4 => {
                println!("bye!");
                break;
            },
            _ => {
                println!("invalid option, please select again");
                continue;
            }
        }
        println!("") // break line
    }
}

fn get_input() -> isize {
    std::io::stdout().flush().unwrap();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().parse().unwrap()
}
