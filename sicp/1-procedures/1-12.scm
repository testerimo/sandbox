(define (pascal-row n)
  (define (iter row passed)
    (if (<= n passed)
        (dec row)
        (iter (inc row) (+ passed row))))
  (iter 1 0))

(define (pascal-col n)
  (define (iter row passed)
    (if (<= n passed)
        (- (dec row) (- passed n))
        (iter (inc row) (+ passed row))))
  (iter 1 0))

(define (pascal-triangle row col)
  (if (or (= col 1) (= col row))
      1
      (+ (pascal-triangle (dec row) (dec col))
         (pascal-triangle (dec row) col))))

(define (pascal n)
  (pascal-triangle (pascal-row n) (pascal-col n)))

(displayln (pascal 10))
(displayln (pascal 11))
(displayln (pascal 12))
(displayln (pascal 13))
(displayln (pascal 42))
