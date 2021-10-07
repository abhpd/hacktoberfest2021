public class SkipList<K extends Comparable, V> {
    public static void main(String[] args) {
        SkipList<Integer, Integer> sk = new SkipList<>();
        sk.insert(0, 2);
        sk.insert(2, 2);
        sk.insert(12, 2);
        sk.insert(6, 1);
        sk.insert(3, 2);
        sk.insert(5, 1);
        sk.insert(3, 2);
        sk.insert(8, 2);
        sk.insert(0, 2);
        sk.insert(4, 2);

        sk.printBottomList();
        System.out.println(sk.findEG(8));
    }

    private class Node<NK extends K, NV extends V> {
        NK k;
        NV v;
        int level;
        Node<NK, NV>[] next;

        Node(int level) {
            this.level = level;
            next = new Node[level];
        }

        Node(NK k, NV v, int level) {
            this.level = level;
            next = new Node[level];
            this.k = k;
            this.v = v;
        }
    }

    private final int MAX_LEVEL = 32;
    private int level = 1;
    private Node<K, V> root = new Node(MAX_LEVEL);

    /**
     * Generate a random level for a new node.
     * @return level
     */
    private int randomLevel() {
        int lvl = 1;
        while (lvl < MAX_LEVEL && Math.random() < 0.5) {
            lvl++;
        }
        return lvl;
    }

    public void insert(K k, V v) {
        Node<K, V> n = new Node(k, v, randomLevel());
        level = Math.max(n.level, level);
        Node<K, V> p = root;
        Node<K, V>[] needUpdates = new Node[n.level];
        // find the right position
        for (int i = level - 1; i >= 0; i--) {
            while (p.next[i] != null && p.next[i].k.compareTo(k) < 0) {
                p = p.next[i];
            }
            if (i < n.level) {
                needUpdates[i] = p;
            }
        }
        // do insert
        for (int i = n.level - 1; i >= 0; i--) {
            n.next[i] = needUpdates[i].next[i];
            needUpdates[i].next[i] = n;
        }
    }

    /**
     * Find the smallest element, whose key is equal or greater than k
     * @param k
     * @return the element's value, null if not found.
     */
    public V findEG(K k) {
        Node<K, V> p = root;
        for (int i = level - 1; i >= 0; i--) {
            while (p.next[i] != null && p.next[i].k.compareTo(k) < 0) {
                p = p.next[i];
            }
        }
        return p.next[0].v;
    }

    public void printBottomList() {
        Node<K, V> p = root;
        while (p.next[0] != null) {
            System.out.print("->(" + p.next[0].k + ", " + p.next[0].v + ")");
            p = p.next[0];
        }
        System.out.println();
    }
}
