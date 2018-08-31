/*
Definition for a binary tree node.
public class TreeNode{
	int val;
	TreeNode left;
	TreeNode right;
	public TreeNode(int val){this.val = val;}
}
*/

//Approach 1: Recursive
/*
Time complexity : O(n). Because we traverse the entire input tree once, the total run time is O(n), where nn is the total number of nodes in the tree.
Space complexity : The number of recursive calls is bound by the height of the tree. In the worst case, the tree is linear and the height is in O(n). Therefore, space complexity due to recursive calls on the stack is O(n)) in the worst case. 
*/
class Solution{
	public boolean isSymmetric(TreeNode root) {
        return func(root, root);
    }
	public func(TreeNode left, TreeNode right){
		if(left==null && right==null) return true;
        else if(left==null || right==null) return false;
        else return left.val==right.val && func(left.left, right.right) && func(left.right, right.left);
	}
	
}

//Approach 2: Iterative
/*
Time complexity : O(n). Because we traverse the entire input tree once, the total run time is O(n), where nn is the total number of nodes in the tree.
Space complexity : There is additional space required for the search queue. In the worst case, we have to insert O(n) nodes in the queue. Therefore, space complexity is O(n).
*/

class Solution {
    
    public boolean isSymmetric(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        if(root!=null){
            q.add(root.left);
            q.add(root.right);
            
            while(!q.isEmpty()){
                TreeNode t1 = q.poll();
                TreeNode t2 = q.poll();
                
                if(t1 == null && t2 == null) continue;
                else if(t1 == null || t2 == null || t1.val != t2.val) return false;
                else{
                    q.add(t1.left);
                    q.add(t2.right);
                    q.add(t1.right);
                    q.add(t2.left);
                }
            }
        }
        return true;
    }
    
}