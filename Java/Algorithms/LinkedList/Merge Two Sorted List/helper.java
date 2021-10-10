public class helper {
    static void outputArray(ListNode node) {
        StringBuilder strB = new StringBuilder();

        while (node != null) {
            if (strB.length() > 0)
                strB.append("->");

            strB.append(node.val);

            node = node.next;
        }

        if (strB.length() > 0)
            strB.append("->");

        strB.append("null");

        System.out.println(strB.toString());
    }

    // Change comment
    public static void main(String[] args) {
        Solution solution = new Solution();

        ListNode list1 = new ListNode(5);
        ListNode list2 = new ListNode(6);

        helper.outputArray(solution.mergeTwoLists(list1, list2));
    }
}
