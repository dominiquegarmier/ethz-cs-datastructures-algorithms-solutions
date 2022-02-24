**Counterexample:**
$$
f(n) = n, \quad g(n) = n + 1
$$

**Explanation:**
$g \in \mathcal{O}(f)$ but the wrong definition would imply that this is not the case.

**Correct compact definition of Theta(f)**

$$
\Theta(f) = \{ g: \N \to \R^+ |  \exists c_1,c_2 > 0, \exists n_0 \in \mathbb{N}: \forall n \leq n_0: 0 \leq c_1 f(n) \leq g(n) \leq c_2  f(n) \}
$$