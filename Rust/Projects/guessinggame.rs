use std::io;
use rand::Rng;

fn main() {

    let secret_number = rand::thread_rng().gen_range(1..101);
    
    loop {
        println!("Please input a number:");
        let mut guess = String::new();
        match io::stdin().read_line(&mut guess){
            Ok(n) => println!("{} bytes read", n),
            Err(error) => println!("Error: {}", error),
        }

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("You guessed: {}", guess);

        match guess.cmp(&secret_number) {
            std::cmp::Ordering::Less => println!("Too small"),
            std::cmp::Ordering::Equal => {println!("You win!"); break;}
            std::cmp::Ordering::Greater => println!("Too large"),
        }
    }


}
