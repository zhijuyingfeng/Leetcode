class Solution {
    fun spiralOrder(matrix: Array<IntArray>): List<Int> {
        val result: MutableList<Int> = mutableListOf()
        spiralOrder(matrix, 0, result)
        return result
    }

    fun spiralOrder(matrix: Array<IntArray>, circle: Int, result: MutableList<Int>) {
        val m = matrix.size
        val n = matrix[0].size

        if (m - circle * 2 == 0 || n - circle * 2 == 0) {
            return
        } else if (m - circle * 2 == 1) {
            for (i in 0..n- 2 * circle - 1) {
                result.add(matrix[circle][circle + i])
            }
            return
        } else if (n - circle * 2 == 1) {
            for (i in 0..m - 2 *circle - 1){
                result.add(matrix[circle + i][circle])
            }
            return
        }
        val horizontalCount = n - 2 * circle - 1
        val verticalCount = m - 2 * circle - 1
        for (i in 0..horizontalCount - 1) {
            result.add(matrix[circle][circle + i])
        }
        for (i in 0..verticalCount - 1) {
            result.add(matrix[circle + i][n - 1 - circle])
        }
        for (i in 0..horizontalCount - 1) {
            result.add(matrix[m - 1 - circle][n - circle - 1 - i])
        }
        for (i in 0..verticalCount - 1) {
            result.add(matrix[m - circle - 1 - i][circle])
        }
        spiralOrder(matrix, circle + 1, result)
    }
}
