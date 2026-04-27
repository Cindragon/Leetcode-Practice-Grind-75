/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let isUsedOnce=false
    var ans=0
    return function(...args){
        if(!isUsedOnce){
            ans=fn(...args)
            isUsedOnce=true
            return ans;
        }
        else{
            return undefined;
        }
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
