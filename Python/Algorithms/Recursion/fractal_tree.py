"""Draw a fractal tree."""

import turtle


def _draw_tree(t: turtle.Turtle,
               branch_len: int,
               shorten_factor: int,
               angle: float,
               min_branch_len: int) -> None:
    if branch_len > min_branch_len:
        t.forward(branch_len)
        new_len = branch_len - shorten_factor
        t.left(angle)
        _draw_tree(t, new_len, shorten_factor, angle, min_branch_len)
        t.right(angle * 2)
        _draw_tree(t, new_len, shorten_factor, angle, min_branch_len)
        t.left(angle)
        t.backward(branch_len)


def main():
    first_branch_len = 50
    shorten_factor = 5
    angle = 30
    min_branch_len = 5

    tree = turtle.Turtle()
    tree.hideturtle()
    tree.setheading(90)  # Rotate tree in right direction
    tree.color('green')
    _draw_tree(tree, first_branch_len, shorten_factor, angle, min_branch_len)
    turtle.mainloop()


if __name__ == "__main__":
    main()

