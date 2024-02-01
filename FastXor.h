#pragma once

#include <emmintrin.h>
#include <cstdint>
#include <string>
#include <vector>

class CFastXor {
public:
	static void Xor(uint8_t* data, size_t dataSize, const uint8_t* key, size_t keySize);

	static __forceinline void Xor(std::vector<uint8_t>& data, const std::vector<uint8_t>& key) {
		Xor(data.data(), data.size(), key.data(), key.size());
	}

	static __forceinline void Xor(std::string& data, const std::vector<uint8_t>& key) {
		Xor((uint8_t*)data.data(), data.size(), key.data(), key.size());
	}
	
	static __forceinline void Xor(std::string& data, const std::string& key) {
		Xor((uint8_t*)data.data(), data.size(), (const uint8_t*)key.data(), key.size());
	}

	static __forceinline void Xor(std::vector<uint8_t>& data, const std::string& key) {
		Xor(data.data(), data.size(), (const uint8_t*)key.data(), key.size());
	}
};
