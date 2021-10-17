function MaxValue(p, q) {
    return (p > q) ? p : q;
}
function knapSackFunc(W, wt, val, n) {
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSackFunc(W, wt, val, n - 1);
    else
        return Maxalue(val[n - 1] +
            knapSackFunc(W - wt[n - 1], wt, val, n - 1),
            knapSackFunc(W, wt, val, n - 1));
}

let val = [60, 100, 120];
let wt = [10, 20, 30];
let W = 50;
let n = val.length;

document.write(knapSackFunc(W, wt, val, n));
