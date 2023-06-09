function enqueue(a, o) { a.push(o); }
function dequeue(a) { return a.shift(); }

var g = { 
  1: {n:[2,5], v:0},
  2: {n:[3,4], v:0},
  3: {n:[4,5,6], v:0},
  4: {n:[5,6], v:0},
  5: {n:[6], v:0},
  6: {n:[], v:0}
};

function init(g) { 
  for (i in g) g[i].v = 0;
}

var queue=[1];

function bfs(g, q) {
  if (q.length == 0) return;
  var node = dequeue(q);     
  if (g[node].v == 0)        
    g[node].v = 1;           
  else                       
    return;
  
  var neighbors = g[node].n;
  for (var i in neighbors) {
    var n = neighbors[i];
    if (!g[n].visited)
      q.push(n);
  }
  bfs(g, q);
}
init(g); 
bfs(g, queue)
