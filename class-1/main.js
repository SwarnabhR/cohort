function square(n) {
    return n * n
}

function cube(n) {
    return n * n * n;
}
function quad(n) {
    return n * n * n * n;
}

function sumOfSomething(a, b, fnCallback) {
    return fnCallback(a) + fnCallback(b);
}
let ans = sumOfSomething(2, 3, cube);
console.log(ans);