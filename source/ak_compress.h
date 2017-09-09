/* ----------------------------------------------------------------------------------------------- */
/*  Copyright (c) 2017 by Axel Kenzo, axelkenzo@mail.ru                                            */
/*                                                                                                 */
/*  Разрешается повторное распространение и использование как в виде исходного кода, так и         */
/*  в двоичной форме, с изменениями или без, при соблюдении следующих условий:                     */
/*                                                                                                 */
/*   1. При повторном распространении исходного кода должно оставаться указанное выше уведомление  */
/*      об авторском праве, этот список условий и последующий отказ от гарантий.                   */
/*   2. При повторном распространении двоичного кода должна сохраняться указанная выше информация  */
/*      об авторском праве, этот список условий и последующий отказ от гарантий в документации     */
/*      и/или в других материалах, поставляемых при распространении.                               */
/*   3. Ни имя владельца авторских прав, ни имена его соратников не могут быть использованы в      */
/*      качестве рекламы или средства продвижения продуктов, основанных на этом ПО без             */
/*      предварительного письменного разрешения.                                                   */
/*                                                                                                 */
/*  ЭТА ПРОГРАММА ПРЕДОСТАВЛЕНА ВЛАДЕЛЬЦАМИ АВТОРСКИХ ПРАВ И/ИЛИ ДРУГИМИ СТОРОНАМИ "КАК ОНА ЕСТЬ"  */
/*  БЕЗ КАКОГО-ЛИБО ВИДА ГАРАНТИЙ, ВЫРАЖЕННЫХ ЯВНО ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ, НО НЕ             */
/*  ОГРАНИЧИВАЯСЬ ИМИ, ПОДРАЗУМЕВАЕМЫЕ ГАРАНТИИ КОММЕРЧЕСКОЙ ЦЕННОСТИ И ПРИГОДНОСТИ ДЛЯ КОНКРЕТНОЙ */
/*  ЦЕЛИ. НИ В КОЕМ СЛУЧАЕ НИ ОДИН ВЛАДЕЛЕЦ АВТОРСКИХ ПРАВ И НИ ОДНО ДРУГОЕ ЛИЦО, КОТОРОЕ МОЖЕТ    */
/*  ИЗМЕНЯТЬ И/ИЛИ ПОВТОРНО РАСПРОСТРАНЯТЬ ПРОГРАММУ, КАК БЫЛО СКАЗАНО ВЫШЕ, НЕ НЕСЁТ              */
/*  ОТВЕТСТВЕННОСТИ, ВКЛЮЧАЯ ЛЮБЫЕ ОБЩИЕ, СЛУЧАЙНЫЕ, СПЕЦИАЛЬНЫЕ ИЛИ ПОСЛЕДОВАВШИЕ УБЫТКИ,         */
/*  ВСЛЕДСТВИЕ ИСПОЛЬЗОВАНИЯ ИЛИ НЕВОЗМОЖНОСТИ ИСПОЛЬЗОВАНИЯ ПРОГРАММЫ (ВКЛЮЧАЯ, НО НЕ             */
/*  ОГРАНИЧИВАЯСЬ ПОТЕРЕЙ ДАННЫХ, ИЛИ ДАННЫМИ, СТАВШИМИ НЕПРАВИЛЬНЫМИ, ИЛИ ПОТЕРЯМИ ПРИНЕСЕННЫМИ   */
/*  ИЗ-ЗА ВАС ИЛИ ТРЕТЬИХ ЛИЦ, ИЛИ ОТКАЗОМ ПРОГРАММЫ РАБОТАТЬ СОВМЕСТНО С ДРУГИМИ ПРОГРАММАМИ),    */
/*  ДАЖЕ ЕСЛИ ТАКОЙ ВЛАДЕЛЕЦ ИЛИ ДРУГОЕ ЛИЦО БЫЛИ ИЗВЕЩЕНЫ О ВОЗМОЖНОСТИ ТАКИХ УБЫТКОВ.            */
/*                                                                                                 */
/*  ak_compress.h                                                                                  */
/* ----------------------------------------------------------------------------------------------- */
#ifndef __AK_COMPRESS_H__
#define __AK_COMPRESS_H__

/* ----------------------------------------------------------------------------------------------- */
 #include <ak_hash.h>

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Структура предназначенная для итеративного вычисления значений сжимающих отображений */
 struct compress
{
 /*! \brief массив, предназначенный для временного хранения обрабатываемых данных */
  ak_uint8 *data;
 /*! \brief длина блока обрабатываемых данных */
  size_t bsize;
 /*! \brief длина хеш-кода (результата применения сжимающего отображения)  */
  size_t hsize;
 /*! \brief количество элементов, хранящихся в массиве data */
  size_t length;
 /*! \brief указатель на контекст сжимающего преобразования */
  ak_pointer ctx;
 /*! \brief функция очистки контекста сжимающего преобразования */
  ak_function_hash_clean *clean;
 /*! \brief функция обработки данных, длина которых кратна длине обрабатываемого блока */
  ak_function_hash_update *update;
 /*! \brief функция завершения сживающего преобразования */
  ak_function_hash_finalize *finalize;
};

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Определение контекста сжимающего отображения */
 typedef struct compress *ak_compress;

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Инициализация контекста сжимающего отображения, реализуемого при помощи функции хеширования. */
 int ak_compress_create_hash( ak_compress , ak_hash );
/*! \brief Уничтожение контекста сжимающего отображения. */
 int ak_compress_destroy( ak_compress );
/*! \brief Освобождение памяти из под контекста сжимающего отображения. */
 ak_pointer ak_compress_delete( ak_pointer );

/*! \brief Очистка контекста сжимающего отображения. */
 int ak_compress_clean( ak_compress );
/*! \brief Обновление состояния контекста сжимающего отображения. */
 int ak_compress_update( ak_compress , const ak_pointer , const size_t );
/*! \brief Обновление состояние и вычисление результата применения сжимающего отображения. */
 ak_buffer ak_compress_finalize( ak_compress , const ak_pointer , const size_t , ak_pointer );
/*! \brief Применение сжимающего отображения к заданному файлу. */
 ak_buffer ak_compress_file( ak_compress , const char* , ak_pointer );

#endif
/* ----------------------------------------------------------------------------------------------- */
/*                                                                                   ak_compress.h */
/* ----------------------------------------------------------------------------------------------- */
