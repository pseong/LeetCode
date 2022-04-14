<h2><a href="https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/">236. 이진 트리의 가장 낮은 공통 조상</a></h2><h3>Medium</h3><hr><div><p _msthash="4176204" _msttexthash="4268017">Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.</p>

<p><font _mstmutation="1" _msthash="4176315" _msttexthash="48231495">According to the <a href="https://en.wikipedia.org/wiki/Lowest_common_ancestor" target="_blank" _mstmutation="1">definition of LCA on Wikipedia</a>: “The lowest common ancestor is defined between two nodes  and  as the lowest node in  that has both  and  as descendants (where we allow <b _mstmutation="1">a node to be a descendant of itself</b>).”</font><code>p</code><code>q</code><code>T</code><code>p</code><code>q</code></p>

<p>&nbsp;</p>
<p><strong _msthash="4176549" _msttexthash="114439">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png" style="width: 200px; height: 190px;">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong> The LCA of nodes 5 and 1 is 3.
</pre>

<p><strong _msthash="4177017" _msttexthash="114621">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png" style="width: 200px; height: 190px;">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
<strong>Output:</strong> 5
<strong>Explanation:</strong> The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
</pre>

<p><strong _msthash="4269044" _msttexthash="114803">Example 3:</strong></p>

<pre><strong>Input:</strong> root = [1,2], p = 1, q = 2
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong _msthash="4269434" _msttexthash="199901">Constraints:</strong></p>

<ul>
	<li><font _mstmutation="1" _msthash="4871464" _msttexthash="1309607">The number of nodes in the tree is in the range .</font><code>[2, 10<sup>5</sup>]</code></li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li><font _mstmutation="1" _msthash="4871724" _msttexthash="219076">All  are <strong _mstmutation="1">unique</strong>.</font><code>Node.val</code></li>
	<li><code>p != q</code></li>
	<li><code>p</code><font _mstmutation="1" _msthash="4871984" _msttexthash="519454"> and  will exist in the tree.</font><code>q</code></li>
</ul>
</div>