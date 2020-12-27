//int count = 0;
//
//if (flag_positon > 31) {
//	//count = (flag_positon / 32 + 1);
//	while (flag_positon > 31) {
//		flag_positon -= 32;
//		count++;
//	}
//	int* pTemp = (int*)realloc(pBit_flags->data, sizeof(int) * (count + 1));
//	if (!pBit_flags->data)
//		return FAILURE;
//	pTemp[count] = (1 << flag_positon) | pTemp[count];
//	pBit_flags->data = pTemp;
//
//
//	/*if (count >= pBit_flags->capacity / 32) {
//		int* pTemp = (int*)realloc(pBit_flags->data, sizeof(int) * (count + 1));
//		if (!pTemp)
//			return FAILURE;
//		for (int i = 0; i <= count; i++)
//			pTemp[i] = pBit_flags->data[i];*/
//
//			/*int* pTemp = (int*)malloc(sizeof(int) * count);
//			if (!pTemp)
//				return FAILURE;
//			for (int i = 0; i < pBit_flags->capacity; i++)
//				pTemp[i] = pBit_flags->data[i];
//			free(pBit_flags->data);
//			pBit_flags->capacity = count;
//			pBit_flags->data = pTemp;*/
//
//	pBit_flags->size = flag_positon + (count * 32);
//	pBit_flags->capacity = (count + 1) * 32;
//
//
//	return SUCCESS;
//}
