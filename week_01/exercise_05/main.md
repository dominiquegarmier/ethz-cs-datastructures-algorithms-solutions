1. statement is true\
Explanation: \
    divding by $0 \leq g(n) \leq cf(n)$ by $c$ gives $0 \leq c'g(n) \leq f(n)$ for $c' = \frac{1}{c}$ and vis versa, which proves the statement. 
---
2. statement is false\
Explanation:\
    $2 \in \mathcal{O}(1)$ for $c = 0.5$
---
3. statement is true\
Explanation: \
    use $c = 1$
---
4. statement is true\
Explanation:\
    $1 \in \Theta(2)$ and $2 \in \Theta(1)$
---
5. statement is true\
Explanation:\
    yes because $\log_a(n) = \frac{\log_b(n)}{\log_b(a)}$ and $\log_b(a)$ is constant.
---
6. statement is true\
Explanation:\
use $c = c_1 + c_2$
---
7. statement is false\
Explanation:\
counterexample: $ x \in \mathcal{O}(x)$ but $x^2 \notin \mathcal{O}(x)$
---
8. statement is false\
Explanation:\
the quotion between $n^{1/a}$ and $n^{1/b}$ is given by $q = n^{1/a - 1/b}$ which is unbounded. hence there exists no (at the same time) $c_1$ and $c_2$ required for the $\mathcal{O}$ definition.