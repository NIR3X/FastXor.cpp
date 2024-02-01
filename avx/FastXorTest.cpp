#include "FastXor.h"

int main() {
	// Key to encrypt with
	std::string key = "YourKey";

	// Data to encrypt
	std::string data = "YourStringData";

	// Encrypt the data
	std::string encrypted = data;
	CFastXor::Xor(encrypted, key);

	// Decrypt the data
	std::string decrypted = encrypted;
	CFastXor::Xor(decrypted, key);

	// Check if the decrypted data matches the original data
	if (decrypted != data) {
		printf("Mismatch: decrypted data does not match the original data\n");
		return 1;
	}

	puts("PASS");
	return 0;
}
