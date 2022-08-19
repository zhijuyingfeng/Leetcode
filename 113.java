import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

class Solution {
    private void helper(TreeNode root, List<List<Integer>>ans, LinkedList<Integer> path , int sum, int targetSum) {
        if (root == null) {
            return;
        }
        if (root.left == null && root.right == null) {
            if (sum + root.val == targetSum) {
                path.push(root.val);
                LinkedList<Integer> copy= new LinkedList<>(path);
                Collections.reverse(copy);
                ans.add(copy);
                path.pop();
            }
            return;
        }

        if (root.left != null) {
            path.push(root.val);
            helper(root.left, ans, path, sum + root.val, targetSum);
            path.pop();
        }

        if (root.right != null) {
            path.push(root.val);
            helper(root.right, ans, path, sum + root.val, targetSum);
            path.pop();
        }
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> ans = new LinkedList<>();
        LinkedList<Integer> path = new LinkedList<>();
        helper(root, ans, path, 0, targetSum);
        return ans;
    }
}
