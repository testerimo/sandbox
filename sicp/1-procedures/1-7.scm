(define (sqrt x)
  (define (good-enough? guess)
    (< (abs (- x (square guess))) 0.001))
  (define (improve guess)
    (average guess (/ x guess)))
  (define (try guess)
    (if (good-enough? guess)
        guess
        (try (improve guess))))
  (try 1.0))

(define (better-sqrt x)
  (define (good-enough? guess prev-guess)
    (< (abs (- guess prev-guess)) 0.001))
  (define (improve guess)
    (average guess (/ x guess)))
  (define (try guess prev-guess)
    (if (good-enough? guess prev-guess)
        guess
        (try (improve guess) guess)))
  (try 1.0 x))

(displayln (sqrt 2))
(displayln (better-sqrt 2))

(displayln (sqrt 9))
(displayln (better-sqrt 9))

(displayln (sqrt 0.000001))
(displayln (better-sqrt 0.000001))

(displayln (better-sqrt 100000000000000000))
; (displayln (sqrt 100000000000000000))
(exit)
