package main;

/**
 * Created by mxu on 16-10-19.
 */
public class DateDiff {
    private int mStartYear;
    private int mEndYear;
    private int mStartMonth;
    private int mEndMonth;
    private int mStartDay;
    private int mEndDay;
    private int[] mDays = {31,28,31,30,31,30,31,31,30,31,30,31};
    private boolean mIsError = false;
    private boolean mIsNegative = false;

    // 获取两个时间天数的神算法
    public static int rdn(int y, int m, int d) { /* Rata Die day one is 0001-01-01 */
        if (m < 3) {
            y--;
            m += 12;
        }

        return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;

        //int days = rdn(2016, 6, 19) - rdn(2011, 8, 21);
    }

    /**
     * 日期格式 2011-08-21
     * @param startDate
     * @param endDate
     */
    public DateDiff(String startDate, String endDate) {
        if (startDate.compareTo(endDate) > 0) {
            String tempDate = endDate;
            endDate = startDate;
            startDate = tempDate;
            mIsNegative = true;
        }

        String[] startSplits = startDate.split("-");
        String[] endSplits = endDate.split("-");

        try {
            mStartYear =  Integer.parseInt(startSplits[0]);
            mEndYear = Integer.parseInt(endSplits[0]);
            mStartMonth = Math.max(Integer.parseInt(startSplits[1]) - 1, 0);
            mEndMonth = Math.max(Integer.parseInt(endSplits[1]) - 1, 0);
            mStartDay = Integer.parseInt(startSplits[2]);
            mEndDay = Integer.parseInt(endSplits[2]);

        } catch (NumberFormatException e) {
            mIsError = true;
        } catch (ArrayIndexOutOfBoundsException e) {
            mIsError = true;
        }
    }

    public boolean hasError() {
        return mIsError;
    }

    /**
     * 另外一种思路：分别计算当前时间到公元0001-01-01的天数，然后相减。
     * int daysYear = 365 * (year - 1) + year / 4 - year / 100 + year / 400;
     * int days = daysYear + 当年的天数（如果月份超过2月，判断是否为闰年）
     * @return
     */
    public int getDays() {
        if (mIsError) {
            return 0;
        }

        int daysEndAtThisYear = mEndDay + (mEndMonth > 2 ? (isLeapYear(mEndYear) ? 1 : 0) : 0);
        for (int m = 0; m < mEndMonth; m++) {
            daysEndAtThisYear += this.mDays[m];
        }

        int daysStartAtThatYear = mStartDay + (mStartMonth > 2 ? (isLeapYear(mStartYear) ? 1 : 0) : 0);
        for (int m = 0; m < mStartMonth; m++) {
            daysStartAtThatYear += this.mDays[m];
        }

        int yearDelta = mEndYear - mStartYear;
        int daysFromYear = 365 * yearDelta;
        for (int y = 0; y < yearDelta; y++) {
            if (isLeapYear(mStartYear + y)) {
                daysFromYear++;
            }
        }

        int totalDays = daysFromYear + (daysEndAtThisYear - daysStartAtThatYear);
        return mIsNegative ? ~totalDays + 1 : totalDays;
    }

    private boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
}
