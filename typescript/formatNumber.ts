/**
 * this snippet formats a string into a pattern given
 * 
 * @param str_num: original number in string format
 * @param fraction: number of digits in fractional part
 * @param group: number of digit in each group
 * @param group_sep: group separator
 * @param dec_sep : decimal separator
 * @returns formated number
 */

const formatNumber = (str_num: string, fraction: number, group: number, group_sep: string, dec_sep: string) => {
    let thisNum = parseFloat(str_num);
    if (!thisNum) return "0";
    let re = '\\d(?=(\\d{' + (group || 3) + '})+' + (fraction > 0 ? '\\D' : '$') + ')',
        num = thisNum.toFixed(Math.max(0, ~~fraction));
    return (dec_sep ? num.replace('.', dec_sep) : num).replace(new RegExp(re, 'g'), '$&' + (group_sep || ','));
}

// examples
formatNumber('34674807381212.625', 4, 3, '.', ',')      // returns 34.674.807.381.212,6250
formatNumber('34674807381212.625', 2, 3, ',', '.')      // returns 34,674,807,381,212.63
formatNumber('34674807381212.625', 4, 4, ' ', '⎖')      // returns 34 6748 0738 1212⎖6250