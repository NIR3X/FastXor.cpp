#include "FastXor.h"

void CFastXor::Xor(uint8_t* data, size_t dataSize, const uint8_t* key, size_t keySize) {
	size_t dataSizeAligned = dataSize & ~0x0f;
	for (size_t i = 0; i < dataSizeAligned; i += 16) {
		__m128i_u* dataPtr = (__m128i_u*)(data + i);
		_mm_storeu_si128(
			dataPtr,
			_mm_xor_si128(
				_mm_loadu_si128(dataPtr),
				_mm_loadu_si128((__m128i_u*)(key + (i % keySize)))
			)
		);
	}
	size_t dataSizeUnaligned = dataSize & 0x0f;
	switch (dataSizeUnaligned) {
	case 1:
		data[dataSizeAligned] ^= key[dataSizeAligned % keySize];
		break;
	case 2:
		*(uint16_t*)(data + dataSizeAligned) ^= *(uint16_t*)(key + (dataSizeAligned % keySize));
		break;
	case 3:
		*(uint16_t*)(data + dataSizeAligned) ^= *(uint16_t*)(key + (dataSizeAligned % keySize));
		data[dataSizeAligned + 2] ^= key[(dataSizeAligned + 2) % keySize];
		break;
	case 4:
		*(uint32_t*)(data + dataSizeAligned) ^= *(uint32_t*)(key + (dataSizeAligned % keySize));
		break;
	case 5:
		*(uint32_t*)(data + dataSizeAligned) ^= *(uint32_t*)(key + (dataSizeAligned % keySize));
		data[dataSizeAligned + 4] ^= key[(dataSizeAligned + 4) % keySize];
		break;
	case 6:
		*(uint32_t*)(data + dataSizeAligned) ^= *(uint32_t*)(key + (dataSizeAligned % keySize));
		*(uint16_t*)(data + dataSizeAligned + 4) ^= *(uint16_t*)(key + (dataSizeAligned + 4) % keySize);
		break;
	case 7:
		*(uint32_t*)(data + dataSizeAligned) ^= *(uint32_t*)(key + (dataSizeAligned % keySize));
		*(uint16_t*)(data + dataSizeAligned + 4) ^= *(uint16_t*)(key + (dataSizeAligned + 4) % keySize);
		data[dataSizeAligned + 6] ^= key[(dataSizeAligned + 6) % keySize];
		break;
	case 8:
		*(uint64_t*)(data + dataSizeAligned) ^= *(uint64_t*)(key + (dataSizeAligned % keySize));
		break;
	case 9:
		*(uint64_t*)(data + dataSizeAligned) ^= *(uint64_t*)(key + (dataSizeAligned % keySize));
		data[dataSizeAligned + 8] ^= key[(dataSizeAligned + 8) % keySize];
		break;
	case 10:
		*(uint64_t*)(data + dataSizeAligned) ^= *(uint64_t*)(key + (dataSizeAligned % keySize));
		*(uint16_t*)(data + dataSizeAligned + 8) ^= *(uint16_t*)(key + (dataSizeAligned + 8) % keySize);
		break;
	case 11:
		*(uint64_t*)(data + dataSizeAligned) ^= *(uint64_t*)(key + (dataSizeAligned % keySize));
		*(uint16_t*)(data + dataSizeAligned + 8) ^= *(uint16_t*)(key + (dataSizeAligned + 8) % keySize);
		data[dataSizeAligned + 10] ^= key[(dataSizeAligned + 10) % keySize];
		break;
	case 12:
		*(uint64_t*)(data + dataSizeAligned) ^= *(uint64_t*)(key + (dataSizeAligned % keySize));
		*(uint32_t*)(data + dataSizeAligned + 8) ^= *(uint32_t*)(key + (dataSizeAligned + 8) % keySize);
		break;
	case 13:
		*(uint64_t*)(data + dataSizeAligned) ^= *(uint64_t*)(key + (dataSizeAligned % keySize));
		*(uint32_t*)(data + dataSizeAligned + 8) ^= *(uint32_t*)(key + (dataSizeAligned + 8) % keySize);
		data[dataSizeAligned + 12] ^= key[(dataSizeAligned + 12) % keySize];
		break;
	case 14:
		*(uint64_t*)(data + dataSizeAligned) ^= *(uint64_t*)(key + (dataSizeAligned % keySize));
		*(uint32_t*)(data + dataSizeAligned + 8) ^= *(uint32_t*)(key + (dataSizeAligned + 8) % keySize);
		*(uint16_t*)(data + dataSizeAligned + 12) ^= *(uint16_t*)(key + (dataSizeAligned + 12) % keySize);
		break;
	case 15:
		*(uint64_t*)(data + dataSizeAligned) ^= *(uint64_t*)(key + (dataSizeAligned % keySize));
		*(uint32_t*)(data + dataSizeAligned + 8) ^= *(uint32_t*)(key + (dataSizeAligned + 8) % keySize);
		*(uint16_t*)(data + dataSizeAligned + 12) ^= *(uint16_t*)(key + (dataSizeAligned + 12) % keySize);
		data[dataSizeAligned + 14] ^= key[(dataSizeAligned + 14) % keySize];
		break;
	}
}
