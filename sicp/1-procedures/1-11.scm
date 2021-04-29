(define (recursion_func n)
  (if (< n 3)
      n
      (+ (recursion_func (- n 3))
         (recursion_func (- n 2))
         (recursion_func (- n 1)))))

(define (iteration_func n)
  (define (iter a b c counter)
    (if (= n counter)
        c
        (iter (+ a b c)
              (+ a)
              (+ b)
              (inc counter))))
  (iter 2 1 0 0))

(displayln (recursion_func 10))
(displayln (iteration_func 10))

(displayln (recursion_func 26))
(displayln (iteration_func 26))
