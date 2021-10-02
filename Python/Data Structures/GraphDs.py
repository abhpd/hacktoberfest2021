class graph:
    def __init__(self,nodes):
        self.nodes=nodes
        self.nodedict={}
        for st,en in self.nodes:
            if(st in self.nodedict):
                (self.nodedict[st]).append(en)
            else:
                self.nodedict[st]=[en]
    def get_paths(self,start,end,path=[]):
        path=path+[start]
        if start == end:
            return [path]
        if(start not in self.nodedict):
            return []
        paths=[]
        for node in self.nodedict[start]:
            if node not in path:
                new_paths=self.get_paths(node,end,path)
                for p in new_paths:
                    paths.append(p)
        return paths
    def get_shortest_path(self,start,end):
        paths=self.get_paths(start,end)
        shpathl=None
        shpath=[]
        for i in paths:
            if(shpathl==None):
                shpath=i
                shpathl=len(i)
            elif len(i) <= shpathl:
                shpathl=len(i)
                shpath=i
        return shpath
routes=[
    ("Mumbai","Delhi"),
    ("Mumbai","Hyderabad"),
    ("Delhi","Paris"),
    ("Hyderabad","Delhi"),
    ("Hyderabad","Bangolore"),
    ("Bangolore","Paris")
]
routegraph=graph(routes)
start=input("Enter start location\n")
end=input("Enter end location\n")
print(routegraph.get_paths(start,end))
print(len(routegraph.get_paths(start,end)))
print(routegraph.get_shortest_path(start,end))
print(len(routegraph.get_shortest_path(start,end)))
