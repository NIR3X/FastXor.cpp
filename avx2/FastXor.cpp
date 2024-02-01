#include "FastXor.h"

void CFastXor::Xor(uint8_t* data, size_t dataSize, const uint8_t* key, size_t keySize) {
	size_t dataSizeAligned = dataSize & ~0x1f;
	for (size_t i = 0; i < dataSizeAligned; i += 32) {
		__m256i_u* dataPtr = (__m256i_u*)(data + i);
		_mm256_storeu_si256(
			dataPtr,
			_mm256_xor_si256(
				_mm256_loadu_si256(dataPtr),
				_mm256_loadu_si256((__m256i_u*)(key + (i % keySize)))
			)
		);
	}
	size_t dataSizeUnaligned = dataSize & 0x1f;
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
	case 16:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128(
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize)))
			)
		);
		break;
	case 17:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128(
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize)))
			)
		);
		data[dataSizeAligned + 16] ^= key[(dataSizeAligned + 16) % keySize];
		break;
	case 18:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128(
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize)))
			)
		);
		*(uint16_t*)(data + dataSizeAligned + 16) ^= *(uint16_t*)(key + (dataSizeAligned + 16) % keySize);
		break;
	case 19:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128(
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize)))
			)
		);
		*(uint16_t*)(data + dataSizeAligned + 16) ^= *(uint16_t*)(key + (dataSizeAligned + 16) % keySize);
		data[dataSizeAligned + 18] ^= key[(dataSizeAligned + 18) % keySize];
		break;
	case 20:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128(
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize)))
			)
		);
		*(uint32_t*)(data + dataSizeAligned + 16) ^= *(uint32_t*)(key + (dataSizeAligned + 16) % keySize);
		break;
	case 21:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128(
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize)))
			)
		);
		*(uint32_t*)(data + dataSizeAligned + 16) ^= *(uint32_t*)(key + (dataSizeAligned + 16) % keySize);
		data[dataSizeAligned + 20] ^= key[(dataSizeAligned + 20) % keySize];
		break;
	case 22:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128(
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize)))
			)
		);
		*(uint32_t*)(data + dataSizeAligned + 16) ^= *(uint32_t*)(key + (dataSizeAligned + 16) % keySize);
		*(uint16_t*)(data + dataSizeAligned + 20) ^= *(uint16_t*)(key + (dataSizeAligned + 20) % keySize);
		break;
	case 23:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128(
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize)))
			)
		);
		*(uint32_t*)(data + dataSizeAligned + 16) ^= *(uint32_t*)(key + (dataSizeAligned + 16) % keySize);
		*(uint16_t*)(data + dataSizeAligned + 20) ^= *(uint16_t*)(key + (dataSizeAligned + 20) % keySize);
		data[dataSizeAligned + 22] ^= key[(dataSizeAligned + 22) % keySize];
		break;
	case 24:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128(
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize)))
			)
		);
		*(uint64_t*)(data + dataSizeAligned + 16) ^= *(uint64_t*)(key + (dataSizeAligned + 16) % keySize);
		break;
	case 25:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128(
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize)))
			)
		);
		*(uint64_t*)(data + dataSizeAligned + 16) ^= *(uint64_t*)(key + (dataSizeAligned + 16) % keySize);
		data[dataSizeAligned + 24] ^= key[(dataSizeAligned + 24) % keySize];
		break;
	case 26:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128(
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize)))
			)
		); 
		*(uint64_t*)(data + dataSizeAligned + 16) ^= *(uint64_t*)(key + (dataSizeAligned + 16) % keySize);
		*(uint16_t*)(data + dataSizeAligned + 24) ^= *(uint16_t*)(key + (dataSizeAligned + 24) % keySize);
		break;
	case 27:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128(
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize)))
			) 
		);
		*(uint64_t*)(data + dataSizeAligned + 16) ^= *(uint64_t*)(key + (dataSizeAligned + 16) % keySize);
		*(uint16_t*)(data + dataSizeAligned + 24) ^= *(uint16_t*)(key + (dataSizeAligned + 24) % keySize);
		data[dataSizeAligned + 26] ^= key[(dataSizeAligned + 26) % keySize];
		break;
	case 28:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128( 
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize))) 
			)
		);
		*(uint64_t*)(data + dataSizeAligned + 16) ^= *(uint64_t*)(key + (dataSizeAligned + 16) % keySize);
		*(uint32_t*)(data + dataSizeAligned + 24) ^= *(uint32_t*)(key + (dataSizeAligned + 24) % keySize);
		break;
	case 29:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128( 
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize))) 
			)
		);
		*(uint64_t*)(data + dataSizeAligned + 16) ^= *(uint64_t*)(key + (dataSizeAligned + 16) % keySize);
		*(uint32_t*)(data + dataSizeAligned + 24) ^= *(uint32_t*)(key + (dataSizeAligned + 24) % keySize);
		data[dataSizeAligned + 28] ^= key[(dataSizeAligned + 28) % keySize];
		break;
	case 30:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128( 
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize))) 
			)
		);
		*(uint64_t*)(data + dataSizeAligned + 16) ^= *(uint64_t*)(key + (dataSizeAligned + 16) % keySize);
		*(uint32_t*)(data + dataSizeAligned + 24) ^= *(uint32_t*)(key + (dataSizeAligned + 24) % keySize);
		*(uint16_t*)(data + dataSizeAligned + 28) ^= *(uint16_t*)(key + (dataSizeAligned + 28) % keySize);
		break;
	case 31:
		_mm_storeu_si128(
			(__m128i_u*)(data + dataSizeAligned),
			_mm_xor_si128( 
				_mm_loadu_si128((__m128i_u*)(data + dataSizeAligned)),
				_mm_loadu_si128((__m128i_u*)(key + (dataSizeAligned % keySize))) 
			)
		);
		*(uint64_t*)(data + dataSizeAligned + 16) ^= *(uint64_t*)(key + (dataSizeAligned + 16) % keySize);
		*(uint32_t*)(data + dataSizeAligned + 24) ^= *(uint32_t*)(key + (dataSizeAligned + 24) % keySize);
		*(uint16_t*)(data + dataSizeAligned + 28) ^= *(uint16_t*)(key + (dataSizeAligned + 28) % keySize);
		data[dataSizeAligned + 30] ^= key[(dataSizeAligned + 30) % keySize];
		break;
	}
}
