int findMax(int intArray[], int arraySize){
  int i, val, id;
  val = 0;
  for (i=0;i<arraySize;i++) {
    if (intArray[i] > val)
      id = i;
  }
  return id;
}

