/* DARUDE SANDSTORM */

long bpm = 140;
long song[][2] ={
  /*{b[4]   , qn + en},//2st bar start  | Darude Start * 3
  {b[4]   , qn + en},
  {b[4]   , en},
  {b[4]   , qn + en},
  {b[4]   , qn + en},
  {e[5]   , en},     //2st bar end
  {e[5]   , qn + en},//3nd bar start
  {e[5]   , qn + en},
  {d[5]   , en},
  {d[5]   , qn + en},
  {d[5]   , qn + en},
  {a[4]   , en},     //3nd bar end
  {b[4]   , qn + en},//4rd bar start
  {b[4]   , qn + en},
  {b[4]   , en},
  {b[4]   , qn + en},
  {b[4]   , qn + en},
  {e[5]   , en},     //4rd bar end
  {b[4]   , qn + en},//5th bar start
  {b[4]   , qn + en},
  {b[4]   , en},
  {b[4]   , qn + en},
  {b[4]   , qn + en},
  {e[5]   , en},   //5th bar end
  {b[4]   , qn + en},//6th bar start
  {b[4]   , qn + en},
  {b[4]   , en},
  {b[4]   , qn + en},
  {b[4]   , qn + en},
  {e[5]   , en},     //6th bar end
  {e[5]   , qn + en},//6th bar start
  {e[5]   , qn + en},
  {d[5]   , en},
  {d[5]   , qn + en},
  {d[5]   , qn + en},
  {a[4]   , en},     //6th bar end
  {b[4]   , qn + en},//7th bar start
  {b[4]   , qn + en},
  {b[4]   , en},
  {b[4]   , qn + en},
  {b[4]   , qn + en},
  {e[5]   , en},     //7th bar end
  {b[4]   , qn + en},//8th bar start
  {b[4]   , qn + en},
  {b[4]   , en},
  {b[4]   , qn + en},
  {b[4]   , qn + en},
  {e[5]   , en},   //8th bar end  | Darude Start end
  {b[3]   , sn},//duh_duh_duh_duh_da Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},//duh_duh_duh_duh_da end
  {r      , fn + en + qn},
  {d[4]   , qn},//duh_duh_duh_duh_da Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},//duh_duh_duh_duh_da end
  {r      , fn + en + qn + fn},
  {b[3]   , sn},//duh_duh_duh_duh_da Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},//duh_duh_duh_duh_da end
  {b[3]   , sn},//duh_duh_duh_duh_da Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},//duh_duh_duh_duh_da end
  {b[3]   , sn},//duh_duh_duh_duh_da Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},//duh_duh_duh_duh_da end
  {b[3]   , sn},//duh_duh_duh_duh_da Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},//duh_duh_duh_duh_da end
  {b[3]   , sn},//duh_duh_duh_duh Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},//duh_duh_duh_duh end
  {b[3]   , sn},//duh_duh_duh_duh Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},//duh_duh_duh_duh end
  {b[3]   , sn},//duh_duh_duh_duh Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},//duh_duh_duh_duh end
  {b[3]   , sn},//duh_duh_duh_duh Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},//duh_duh_duh_duh end
  {b[3]   , sn},//duh_duh_duh_duh Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},//duh_duh_duh_duh end
  {b[3]   , sn},//duh_duh_duh_duh Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},//duh_duh_duh_duh end
  {b[3]   , sn},//duh_duh_duh_duh Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},//duh_duh_duh_duh end
  {d[4]   , qn},*/
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {e[4]   , sn},//Darude Down
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , en},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , en},
  {a[3]   , sn},
  {a[3]   , sn},//Darude Down end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {e[4]   , sn},//Darude Down
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , en},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , en},
  {a[3]   , sn},
  {a[3]   , sn},//Darude Down end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end

  {e[4]   , sn},//Darude Down
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , en},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , en},
  {a[3]   , sn},
  {a[3]   , sn},//Darude Down end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {e[4]   , sn},//Darude Down
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , en},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , en},
  {a[3]   , sn},
  {a[3]   , sn},//Darude Down end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  /*
  {b[3]   , sn},//darude_up_duh_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {d[4]   , en},//darude_up_duh_da End
  {b[3]   , sn},//darude_up_da_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {d[4]   , en},
  {d[4]   , en},//darude_up_da_da end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {e[4]   , sn},//Darude Down
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , en},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , en},
  {a[3]   , sn},
  {a[3]   , sn},//Darude Down end
  {b[3]   , sn},//darude_up_duh_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {d[4]   , en},//darude_up_duh_da End
  {b[3]   , sn},//darude_up_da_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {d[4]   , en},
  {d[4]   , en},//darude_up_da_da end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {e[4]   , sn},//Darude Down
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , en},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , en},
  {a[3]   , sn},
  {a[3]   , sn},//Darude Down end
  {b[3]   , sn},//darude_up_da_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {d[4]   , en},
  {d[4]   , en},//darude_up_da_da end
  {b[3]   , sn},//darude_up_da_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {d[4]   , en},
  {d[4]   , en},//darude_up_da_da end
  {b[3]   , sn},//darude_up_da_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {d[4]   , en},
  {d[4]   , en},//darude_up_da_da end
  {b[3]   , sn},//darude_up_da_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {d[4]   , en},
  {d[4]   , en},//darude_up_da_da end
  {b[3]   , sn},//duh_duh_duh_da_da start
  {b[3]   , sn},
  {b[3]   , en},
  {d[4]   , en},
  {d[4]   , en},//duh_duh_duh_da_da end
  {b[3]   , sn},//duh_duh_duh_da_da start
  {b[3]   , sn},
  {b[3]   , en},
  {d[4]   , en},
  {d[4]   , en},//duh_duh_duh_da_da end
  {b[3]   , sn},//duh_duh_duh_da_da start
  {b[3]   , sn},
  {b[3]   , en},
  {d[4]   , en},
  {d[4]   , en},//duh_duh_duh_da_da end
  {b[3]   , sn},//duh_duh_duh_da_da start
  {b[3]   , sn},
  {b[3]   , en},
  {d[4]   , en},
  {d[4]   , en},//duh_duh_duh_da_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {e[5]   , fn}*/
};
