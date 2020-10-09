// Function to create a proxy that listens to changes in object.
// Uses a deep recursive proxy, that will always listen to deep changes to the object.
function monitObject(rootObject, callback) {
    function monitObjectInner(obj, path) {
        return new Proxy(obj, {
            get(target, key) {
                if (typeof obj[key] === 'object' && obj[key] !== null) {
                    return monitObjectInner(obj[key], path.concat(key));
                }
                return obj[key];
            },
            set(target, key, value) {
                callback(key, value, path);
                obj[key] = value;
                return true;
            },
        });
    }
    return monitObjectInner(rootObject, []);
}


const obj = monitObject(
    { a: { b: 2, c: { d: 3 } } }, 
    (key, value, path) => console.log(key, value, path),
);

obj.a.b = 4 // 'b', 4, [];
obj.a.f = 5 // 'f', 5, ['a'];
obj.a.c.d = 6 // 'd', 6, ['a', 'c'];
