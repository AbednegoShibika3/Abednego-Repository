#include <iostream>
#include <thread>
#include <vector>
#include <cmath>

bool is_prime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void find_primes(int start, int end, std::vector<int>& primes) {
	for (int i = start; i <= end; ++i) {
		if (is_prime(i)) primes.push_back(i);
	}
}

int main() {
	const int range_start = 1;
	const int range_end = 10000;
	
	std::vector<int> primes1, primes2;
	
	std::thread t1(find_primes, range_start, range_end / 2, std::ref(primes1));
	std::thread t2(find_primes, range_end / 2 + 1, range_end, std::ref(primes2));
	
	t1.join();
	t2.join();
	
	primes1.insert(primes1.end(), primes2.begin(), primes2.end());
	
	primes1.insert(primes1.end(), primes2.begin(), primes2.end());
	
	std::cout << "Found " << primes1.size() << "prime numbers." << std::endl;
	
	return 0;
}