import "./StartRating.css";

type StartRatingProps = {
  stars: number;
};

export default function StarRating({ stars }: StartRatingProps) {
  const starPercentage = (stars / 10) * 100;

  const starPercentageRounded = Math.round(starPercentage);

  const StarStyles = () => {
    return {
      width: starPercentageRounded + "%",
    };
  };

  return (
    <div className="stars-gray">
      <div className="stars-yellow" style={StarStyles()}></div>
    </div>
  );
}
