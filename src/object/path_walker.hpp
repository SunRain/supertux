//  $Id: path.hpp 3114 2006-03-23 23:47:04Z sommer $
// 
//  SuperTux Path
//  Copyright (C) 2005 Philipp <balinor@pnxs.de>
//  Copyright (C) 2006 Christoph Sommer <christoph.sommer@2006.expires.deltadevelopment.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
// 
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
//  02111-1307, USA.
#ifndef __PATH_WALKER_HPP__
#define __PATH_WALKER_HPP__

#include "path.hpp"
#include "math/vector.hpp"
#include "game_object.hpp"
#include "lisp/lisp.hpp"
#include "serializable.hpp"

/**
 * A walker that travels along a path
 */
class PathWalker
{
public:
  PathWalker(const Path* path);
  virtual ~PathWalker();

  /**
   * advanves the path walker on the path and returns the position delta
   * to the last position
   */
  virtual Vector advance(float elapsed_time);

private:
  void advance_node();
  void goback_node();
  
  const Path* path;

  size_t current_node_nr;
  size_t next_node_nr;

  Vector last_pos;

  /** the time we already spend in the current node */
  float node_time;

  float walking_speed;
};

#endif