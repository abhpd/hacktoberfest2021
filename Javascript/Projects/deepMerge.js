function deepMerge(target, ...objects) {
    for (const object of objects) {
        for (const [key, value] of Object.entries(object)) {
            if (typeof value === 'object' && value !== null) {
                if (Array.isArray(value)) {
                    if (!Array.isArray(target[key])) {
                        throw new Error('can\'t merge non array to an array object');
                    }
                    target[key] = target[key].concat(value);
                } else {
                    if (typeof value !== 'object' || value === null || Array.isArray(value)) {
                        throw new Error('can\'t merge a non object to an object');
                    }
                    target[key] = deepMerge(target[key] || {}, value);
                }
            } else {
                target[key] = value;
            }
        }
    }
    return target;
}

deepMerge({}, {a: 3}); //{a: 3}
deepMerge({}, {a: 3, b: 4}); // {a: 3, b: 4}
deepMerge({c: {d: 4}}, {a: 3, b: 4, c: {e: 5}}); // {c: {d: 4, e: 5}, a: 3, b: 4}
deepMerge({c: {d: 4}}, {a: 3, b: 4, c: {d: [1,2,3]}}); 
// Uncaught Error: can't merge non array to an array object
deepMerge({c: {d: {}}}, {a: 3, b: 4, c: {d: [1,2,3]}}); 
// Uncaught Error: can't merge non array to an array object
deepMerge({c: {d: [1,2,3]}}, {a: 3, b: 4, c: {d: [4,5,6]}});
// {c: {d: [1, 2, 3, 4, 5, 6]}, a: 3, b: 4}
deepMerge({a: 3}, {b: 4}, {f: 5}); // {a: 3, b: 4, f: 5}
deepMerge({a: {b: {c: 3}}}, {a: {b: {d: 5}}}) // {a: {b: {c: 3, d: 5}}}
