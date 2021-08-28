/* ALL STAR */
/*
long bpm = 108;
long song[][2] = {
 {r     , hn},//1st bar start
  {r     , qn},
  {bb[4] , qn},//first bar end
  {f[5]  , en},//2nd bar start
  {d[5]  , en},
  {d[5]  , qn},
  {c[5]  , en},
  {bb[4] , en},
  {bb[4] , en},
  {eb[5] , en},//2nd bar end
  {eb[5] , en},//3rd bar start
  {d[5]  , en},
  {d[5]  , en},
  {c[5]  , en},
  {c[5]  , en},
  {bb[4] , en},
  {r     , en},
  {bb[4] , en},//3rd bar end
  {f[5]  , en},//4th bar start
  {d[5]  , en},
  {d[5]  , en},
  {c[5]  , en},
  {c[5]  , en},
  {bb[4] , en},
  {bb[4] , en},
  {g[4]  , en},//4th bar end
  {g[4]  , qn},//5th bar start
  {r     , qn},
  {bb[4] , en},
  {bb[4] , en},//5th bar end
  {f[5]  , en},//6th bar start
  {d[5]  , en},
  {d[5]  , en},
  {c[5]  , en},
  {c[5]  , en},
  {bb[4] , en},
  {bb[4] , en},
  {eb[5] , en},//6th bar end
  {eb[5] , en},//7th bar start
  {d[5]  , en},
  {d[5]  , en},
  {c[5]  , en},
  {c[5]  , en},
  {bb[4] , en},
  {bb[4] , qn},//7th bar end
  {f[5]  , en},//8th bar start
  {d[5]  , en},
  {d[5]  , en},
  {c[5]  , en},
  {c[5]  , en},
  {bb[4] , qn},
  {bb[4] , qn},
  {c[5]  , qn},//8th bar end//9th bar start
  {g[4]  , en},
  {r     , qn},
  {bb[4] , en},
  {g[4]  , en},//9th bar end
  {bb[4] , en},//10th bar start
  {bb[4] , en},
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , en},
  {bb[4] , en},
  {bb[4] , en},
  {bb[4] , en},//10th bar end
  {bb[4] , en},//11th bar start
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , en},
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , en},
  {c[5]  , en},
  {bb[4] , en},//11th bar end
  {d[5]  , sn},//12th bar start
  {d[5]  , sn},
  {f[5]  , en},
  {eb[5] , en},
  {d[5]  , sn},
  {c[5]  , sn},
  {c[5]  , en},
  {c[5]  , en},
  {c[5]  , en},
  {bb[4] , en},//12th bar end
  {d[5]  , en},//13th bar start
  {bb[4] , en},
  {bb[4] , en},
  {f[4]  , sn},
  {f[4]  , sn},
  {bb[4] , en},
  {bb[4] , en},
  {g[4]  , en},
  {f[4]  , en},//13th bar end
  {d[5]  , sn},//14th bar start
  {f[5]  , en},
  {d[5]  , sn},
  {g[5]  , en},
  {d[5]  , sn},
  {f[5]  , sn},
  {f[5]  , sn},
  {d[5]  , sn},
  {g[5]  , en},
  {d[5]  , en},
  {f[5]  , en},//14th bar end
  {eb[5] , en},//15th bar start
  {d[5]  , en},
  {c[5]  , en},
  {bb[4] , en},
  {c[5]  , en},
  {bb[4] , en},
  {r     , en},
  {f[4]  , en},//15th bar end
  {bb[4] , sn},//16th bar start
  {bb[4] , sn},
  {bb[4] , en},
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , en},
  {bb[4] , qn},
  {r     , en},
  {f[4]  , en},//16th bar end
  {d[5]  , sn},//17th bar start
  {bb[4] , sn},
  {bb[4] , en},
  {bb[4] , sn},
  {bb[4] , sn},
  {g[4]  , en},
  {g[4]  , qn},
  {r     , qn},//17th bar end
  {d[5]  , en},//18th bar start
  {bb[4] , qn},
  {bb[4] , sn},
  {g[4]  , sn},
  {bb[4] , en},
  {bb[4] , qn},
  {bb[4] , sn},
  {g[4]  , sn},//18th bar end
  {bb[4] , en},//19th bar start
  {bb[4] , qn},
  {bb[4] , qn},
  {d[5]  , qn},
  {d[5]  , en},//19th bar end
  {d[5]  , en},//20th bar start
  {bb[4] , qn},
  {bb[4] , sn},
  {g[4]  , sn},
  {bb[4] , en},
  {bb[4] , qn},
  {bb[4] , sn},
  {g[4]  , sn},//20th bar end
  {bb[4] , en},//21st bar start
  {bb[4] , qn},
  {bb[4] , qn},
  {d[5]  , qn},
  {d[5]  , en},//21st bar end
  {d[5]  , qn},//22nd bar start
  {f[5]  , qn},
  {eb[5] , en},
  {d[5]  , en},
  {c[5]  , en},
  {c[5]  , en},//22nd bar end
  {c[5]  , en},//23rd bar start
  {bb[4] , en+qn},
  {bb[4] , en},
  {bb[4] , en},
  {c[5]  , en},
  {bb[4] , en},//23rd bar end
  {d[5]  , en},//24th bar start
  {c[5]  , en+qn},
  {c[5]  , en},
  {bb[4] , qn},
  {c[5]  , en},
  {c[5]  , en},
  {d[5]  , en},
  {g[4]  , hn},
  {r     , qn}
};
*/
/* END ALL STAR */
