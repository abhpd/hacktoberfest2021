#!r6rs

(library
 (binary-search-tree-with-current)
 (export new bst? find insert! delete! empty? full? root get-current has-current? set-current-to-first! set-current-to-next!) ; vier nieuwe operaties
 (import (prefix (a-d tree binary-tree) tree:)
         (rnrs base)
         (rnrs io simple)
         (srfi :9)
         (rnrs mutable-pairs))

 (define-record-type bst
   (make r e l c) ; extra parameter
   bst?
   (r root root!)
   (e equality)
   (l lesser)
   (c current current!)) ; extra veld in record type, zal een lijst met de huidige knoop en al zijn voorouders bevatten

 (define (new ==? <<?)
   (make tree:null-tree ==? <<? '())) ; initiële waarde voor current is de lege lijst

 (define (find bst key)
   (define <<? (lesser bst))
   (define ==? (equality bst))
   (let find-key
     ((node (root bst)))
     (if (tree:null-tree? node)
       #f
       (let
           ((node-value (tree:value node)))
         (cond
           ((==? node-value key)
            node-value)
           ((<<? node-value key)
            (find-key (tree:right node)))
           ((<<? key node-value)
            (find-key (tree:left node))))))))

 (define (insert! bst val)
   (define <<? (lesser bst))
   (let insert-iter
     ((parent tree:null-tree)
      (child! (lambda (ignore child) (root! bst child)))
      (child (root bst)))
     (cond
       ((tree:null-tree? child)
        (child! parent
                (tree:new val
                          tree:null-tree
                          tree:null-tree)))
       ((<<? (tree:value child) val)
        (insert-iter child tree:right!
                     (tree:right child)))
       ((<<? val (tree:value child))
        (insert-iter child tree:left!
                     (tree:left child)))
       (else
        (tree:value! child val)))))

 (define (delete! bst val)
   (define <<? (lesser bst))
   (define ==? (equality bst))
   (define (find-leftmost deleted parent child! child)
     (if (tree:null-tree? (tree:left child))
       (begin
         (tree:value! deleted (tree:value child))
         (child! parent (tree:right child)))
       (find-leftmost deleted child
                      tree:left!
                      (tree:left child))))
   (define (delete-node parent child! child)
     (cond
       ((tree:null-tree? (tree:left child))
        (child! parent (tree:right child)))
       ((tree:null-tree? (tree:right child))
        (child! parent (tree:left child)))
       (else
        (find-leftmost child
                       child
                       tree:right!
                       (tree:right child)))))
   (let find-node
     ((parent tree:null-tree)
      (child! (lambda (ignore child) (root! bst child)))
      (child (root bst)))
     (cond
       ((tree:null-tree? child)
        #f)
       ((==? (tree:value child) val)
        (delete-node parent child! child)
        (tree:value child))
       ((<<? (tree:value child) val)
        (find-node child tree:right! (tree:right child)))
       ((<<? val (tree:value child))
        (find-node child tree:left! (tree:left child))))))

 (define (empty? bst)
   (tree:null-tree? (root bst)))

 (define (full? bst)
   #f)

 (define (get-current bst) ; geeft de waarde van de huidige knoop terug
   (if (has-current? bst)
       (tree:value (car (current bst)))
       (error "The BST does not have a current!")))

 (define (has-current? bst)
   (not (null? (current bst))))

 ; hulpfunctie
 (define (set-current-to-leftmost! bst start-node)
   (let loop ; we itereren vanaf de start-node zo ver mogelijk naar links (= het kleinste element)
     ((node start-node))
     (if (not (tree:null-tree? node))
         (begin (current! bst (cons node (current bst))) ; we voegen de huidige knoop steeds vooraan in de lijst van knopen toe
                (loop (tree:left node))))))

 (define (set-current-to-first! bst)
   (current! bst '()) ; we resetten de current
   (set-current-to-leftmost! bst (root bst)))

 ; Of door current lopen tot eerste node met een waarde > de huidige node
 (define (set-current-to-next! bst)
   (define (set-current-to-first-larger-ancestor) ; hulpfunctie die naar boven gaat tot als we van links komen (want dan hebben we onze eerste grotere ouder gevonden)
     (let loop ()
       (let ((current-node (car (current bst))))
         (current! bst (cdr (current bst))) ; we verwijderen de huidige knoop uit de lijst van knopen (= we gaan een niveau hoger in de boom)
         (let ((parent-node (car (current bst))))
           (if (not (eq? current-node (tree:left parent-node))) ; controleer of de huidige knoop het linker kind van de parent was, zoniet moeten we verder naar boven toe gaan
               (if (null? (cdr (current bst))) ; we kunnen niet verder naar boven, want we hebben alle elementen al bezocht
                   (current! bst '()) ; we resetten de current
                   (loop))))))) ; (recursieve oproep)
   (if (has-current? bst)
       (let ((current-node (car (current bst))))
         (if (tree:null-tree? (tree:right current-node)) ; als we geen rechter kind hebben, moet onze opvolger één van onze ouders zijn
             (set-current-to-first-larger-ancestor) ; we zoeken die ouder door middel van een hulpfunctie
             (set-current-to-leftmost! bst (tree:right current-node)))) ; anders is onze opvolger het kleinste element van ons rechter kind
       (error "The BST does not have a current!"))))

