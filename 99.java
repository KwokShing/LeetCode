package Hard.p099;

import Nodes.TreeNode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by Krossing on 1/1/17.
 */
//public class Solution {
//    long max = Long.MIN_VALUE;
//    long min = Long.MAX_VALUE;
//    TreeNode left;
//    TreeNode right;
//    boolean flag = false;
//
//    private void DFS(TreeNode root) {
//        if (root == null)
//            return;
//        DFS(root.left);
//        if (!flag) {
//            if (root.val > max) {
//                max = root.val;
//                left = root;
//            } else if (root.val < max) {
//                flag = true;
//            }
//        }
//        if (flag) {
//            if (root.val < min) {
//                min = root.val;
//                right = root;
//            }
//        }
//        DFS(root.right);
//    }
//
//    public void recoverTree(TreeNode root) {
//        if (root == null)
//            return;
//        DFS(root);
//        left.val = (int) min;
//        right.val = (int) max;
//    }
//}

public class Solution {
    public void recoverTree(TreeNode root) {
        TreeNode left = new TreeNode(Integer.MIN_VALUE);
        TreeNode right = new TreeNode(Integer.MAX_VALUE);
        boolean flag = true;
        while (root != null) {
            if (root.left == null) {
                if (flag) {
                    if (root.val > left.val) {
                        left = root;
                    } else {
                        flag = false;
                    }
                }
                if (!flag) {
                    if (root.val < right.val)
                        right = root;
                }
                root = root.right;
            } else {
                TreeNode pre = root.left;
                while (pre.right != null && pre.right != root)
                    pre = pre.right;
                if (pre.right == null) {
                    pre.right = root;
                    root = root.left;
                } else {
                    pre.right = null;
                    if (flag) {
                        if (root.val > left.val) {
                            left = root;
                        } else {
                            flag = false;
                        }
                    }
                    if (!flag) {
                        if (root.val < right.val)
                            right = root;
                    }
                    root = root.right;
                }
            }
        }
        int tmp = left.val;
        left.val = right.val;
        right.val = tmp;
    }
}