class Solution:
    def isSubFolder(self, seen, folder_path, name=''):
        for ch in folder_path:
            if ch == '/' and name in seen:
                return True
            name += ch
        return name in seen
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        seen = set()
        folder.sort()
        for folder_path in folder:
            if not self.isSubFolder(seen, folder_path):
                seen.add(folder_path)
        return list(seen)