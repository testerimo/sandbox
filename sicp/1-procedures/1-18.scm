(define (double x) (+ x x))

(define (halve x) (/ x 2))

(define (* a b)
  (define (iter a b c)
    (cond ((= b 0) c)
          ((even? b) (iter (double a) (halve b) c))
          (else (iter a (dec b) (+ a c)))))
  (iter a b 0))

(displayln (* 0 8))
(displayln (* 3 7))
(displayln (* 7 8))
(displayln (* 123 456))
