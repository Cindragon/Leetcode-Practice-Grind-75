/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const cache={}; //快取儲存已經計算過的參數
    return function(...args) {
        const key=args.toString();
        if(key in cache){
            return cache[key];
        }
        const ans=fn(...args);
        cache[key]=ans;
        return ans;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */