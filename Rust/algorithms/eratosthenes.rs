use std::env;
use std::time::SystemTime;

fn main() {
	let end = 10_000;
	let mut primes = vec![true; end];

	let start = SystemTime::now();

	primes[0] = false;
	primes[1] = false;

	for n in 2..end {
		for multiple in ((n << 1)..end).step_by(n) {
			primes[multiple] = false;
		}
	}

	let time = SystemTime::now()
		.duration_since(start)
		.unwrap();

	// Print primes if "print" arg passed
	let args: Vec<String> = env::args().collect();
	if args.len() > 1 && args[1] == "print" {
		primes
			.iter()
			.enumerate()
			.filter(|(_, b)| -> bool {**b})
			.for_each(|(i, _)| println!("{}", i));
	}

	println!("Time taken: {} seconds", time.as_secs_f64());
}