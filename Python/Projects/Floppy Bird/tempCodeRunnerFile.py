H_SCORE
    if currentScore > HIGH_SCORE:
        with open("high_score.txt", "w") as score:
            score.write(str(currentScore))
            HIGH_SCOR