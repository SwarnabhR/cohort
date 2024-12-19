const input = [1, 2, 3, 4, 5];
/*
for (let i = 0; i < input.length; i++) {
    newArray.push(input[i] * 3);
}

console.log(newArray);
*/
/*
function transform(newArray) {
    return i * 2;
}
*/
/*
const ans = input.map(function (i) {
    return i * 2;
});
console.log(ans);
*/
const ans = input.filter(function (i) {
    return i % 2 === 0;
});
console.log(ans);