(define (sum-of-squares a b)
  (+ (square a) (square b)))

(define  (sum-of-greatest-squares a b c)
  (cond ((and (>= a c) (>= b c)) (sum-of-squares a b))
        ((and (>= a b) (>= c b)) (sum-of-squares a c))
        (else (sum-of-squares b c))))

(displayln (sum-of-greatest-squares 4 1 1))
(displayln (sum-of-greatest-squares 5 5 4))
(displayln (sum-of-greatest-squares 1 4 4))
(displayln (sum-of-greatest-squares 1 0 1))
(exit)
