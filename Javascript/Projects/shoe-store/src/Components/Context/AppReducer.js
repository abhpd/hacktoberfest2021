export default (state, action) => {
  switch (action.type) {
    case "addCart":
      return {
        ...state,
        cart: [
          state.products.find((p) => p._id === action.payload),
          ...state.cart,
        ],
      };
    case "deletProd":
      return {
        ...state,
        cart: state.cart.filter((pd) => pd._id !== action.payload)
        }
    default:
      return state;
  }
};
