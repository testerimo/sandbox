(define (double x) (+ x x))

(define (halve x) (/ x 2))

(define (* a b)
  (cond ((= b 0) 0)
        ((even? b) (* (double a) (halve b)))
        (else (+ a (* a (dec b))))))

(displayln (* 0 8))
(displayln (* 3 7))
(displayln (* 7 8))
(displayln (* 123 456))
