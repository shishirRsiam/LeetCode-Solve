class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        store = defaultdict(TreeNode)
        parentStore, childStore = set(), set()

        for parent, child, direction in descriptions:
            parentStore.add(parent)
            childStore.add(child)

            if parent not in store:
                store[parent] = TreeNode(parent)
            
            if direction:
                if child not in store:
                    store[child] = TreeNode(child)
                store[parent].left = store[child]
            else:
                if child not in store:
                    store[child] = TreeNode(child)
                store[parent].right = store[child]
                
        for parent in parentStore:
            if parent not in childStore:
                return store[parent]