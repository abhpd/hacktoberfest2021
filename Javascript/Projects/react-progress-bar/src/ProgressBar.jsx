import { useEffect, useState } from "react";

const ProgressBar = () => {
  const [widthToSet, setWidthToSet] = useState(0);
  const parentWidth = 600;
  const [percent, setPercent] = useState(10);
  useEffect(() => {
    setWidthToSet(percent);
    if (percent < 100) {
      setTimeout(() => {
        setPercent(percent + 10);
      }, 100);
    }
  }, [percent]);
  return (
    <div className="container" style={{ width: parentWidth }}>
      <div style={{ width: `${widthToSet}%` }} className="progress-bar"></div>
      <p>Percent: {widthToSet}%</p>
    </div>
  );
};

export default ProgressBar;
