function rangeOfNumbers(startNum, endNum) {
  if(endNum<startNum){
    return [];
  }
  const Array=rangeOfNumbers(startNum, endNum-1)
  Array.push(endNum);
  return Array;
};
console.log(rangeOfNumbers(1,5));
